# CONFIGURACION
################

# Nombre del ejecutable.
target = client

# Extensión de los archivos a compilar (c para C, cpp o cc o cxx para C++).
extension = cpp
# Si usa threads, descomentar (quitar el '#' a) la siguiente línea.
threads = si

# Si usa funciones de math.h, descomentar (quitar el '#' a) la siguiente línea.
math = si

# Si es un programa SDL, descomentar (quitar el '#' a) la siguiente línea.
sdl = si

# CONFIGURACION "AVANZADA"
###########################

# Opciones para el compilador C/C++ para tratamiento de errores y warnings.
CFLAGS = -Wall -Werror -pedantic -pedantic-errors

# Para optimizar el binario resultante lo mejor posible
CFLAGS += -O3

# Para valgrind o debug
CFLAGS += -ggdb -DDEBUG -fno-inline

# Opciones del enlazador.
#LDFLAGS =

# Estandar de C a usar
CSTD = c99

# Estandar de C++ a usar
CXXSTD = c++11

# VARIABLES CALCULADAS A PARTIR DE LA CONFIGURACION
####################################################

# Linkea con libm de ser necesario.
ifdef math
LDFLAGS += -lm
endif

# Linkea con threads de ser necesario. Permite el uso de pthread en C y C++. Permite el uso de built-in threads en C++.
ifdef threads
LDFLAGS += -pthread
endif

ifdef sdl
#LDFLAGS specifies the libraries we're linking against
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
endif

# Se reutilizan los flags de C para C++ también
CXXFLAGS += $(CFLAGS)

# Se usa enlazador de c++ si es código no C.
ifeq ($(extension), c)
CFLAGS += -std=$(CSTD)
LD = $(CC)
else
CXXFLAGS += -std=$(CXXSTD)
LD = $(CXX)
endif

# Si no especifica archivos, tomo todos.
fuentes ?= $(wildcard *.$(extension)) $(wildcard */*.$(extension))
directorios = $(shell find . -type d -regex '.*\w+')

occ := $(CC)
ocxx := $(CXX)
orm := $(RM)
old := $(LD)

# REGLAS
#########

.PHONY: all clean

all: $(target)

o_files = $(patsubst %.$(extension),%.o,$(fuentes))

$(target): $(o_files)
	@if [ -z "$(o_files)" ]; \
	then \
		echo "No hay archivos de entrada en el directorio actual. Recuerde que la extensión debe ser '.$(extension)' y que no se aceptan directorios anidados."; \
		if [ -n "$(directorios)" ]; then echo "Directorios encontrados: $(directorios)"; fi; \
		false; \
	fi >&2
	$(LD) $(o_files) -o $(target) $(LDFLAGS)

clean:
	$(RM) $(o_files) $(target)
