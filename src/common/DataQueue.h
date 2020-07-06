#ifndef DATAQUEUE_H
#define DATAQUEUE_H

#include "BlockingQueue.h"
#include "Message.h"
#include <utility>
#include <vector>

using DataQueue = BlockingQueue<Message>;

#endif