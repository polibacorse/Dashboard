/*
 * Copyright (c) 2018 Poliba Corse
 * Authors: Giovanni Grieco <giovanni.grc96@gmail.com>
 *
 * Part of this code was inspired by
 *  - Alessandro Pezzato (https://github.com/alepez/MosQtitto)
 */

#include "mosquittoreceiversingleton.h"

static MosquittoReceiver *instance{nullptr};

MosquittoReceiver* MosquittoReceiverSingleton::get() {
  return instance;
}

void MosquittoReceiverSingleton::set(MosquittoReceiver *newInstance) {
  instance = newInstance;
}
