# Argentum-Taller

## Proceso de Instalación
Antes de instalar el juego es necesario tener instaladas las librerías mencionadas previamente, para ello se deberá ejecutar el siguiente comando en la consola, que las descargará e instalará:

<pre><code>
    sudo apt-get install libsdl2-dev libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev
</code></pre>

Luego, es necesario proceder a instalar el juego. Para ello, se deberá descomprimir el archivo con todo el código fuente. Una vez descomprimido, abrimos una terminal en la carpeta y ejecutamos los siguientes comandos:

<pre><code>
    cmake CMakeLists.txt
    sudo make install
</code></pre>

Una vez ejecutados estos dos comandos ya estaríamos en condiciones de jugar al Argentum.