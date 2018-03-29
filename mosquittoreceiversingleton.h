/*
 * Copyright (c) 2018 Poliba Corse
 * Authors: Giovanni Grieco <giovanni.grc96@gmail.com>
 *
 * Part of this code have been inspired by
 *  - Alessandro Pezzato (https://github.com/alepez/MosQtitto)
 */

#ifndef MOSQUITTORECEIVERSINGLETON_H
#define MOSQUITTORECEIVERSINGLETON_H

#include "mosquittoreceiver.h"

class MosquittoReceiverSingleton
{
public:
    MosquittoReceiver *get();
    static void set(MosquittoReceiver *);
};

#endif // MOSQUITTORECEIVERSINGLETON_H
