#pragma once

#include "tweaks/tweaks.h"

#include <ll/api/reflection/Dispatcher.h>

using ll::reflection::Dispatcher;

namespace mintvanilla {

struct Config {
  int version = 1;
  struct {
    Dispatcher<bool, allowclientresourcepack::AllowClientResourcePack> allowClientResourcePack = true;
    Dispatcher<bool, fakeseed::FakeSeed> fakeSeed = true;
    Dispatcher<bool, forcetrustedskin::ForceTrustedSkin> forceTrustedSkin = true;
    Dispatcher<bool, hideoperator::HideOperator> hideOperator = true;
  } tweaks{};
  struct {
    int seed = -777;
  } extras{};
};

} // namespace mintvanilla