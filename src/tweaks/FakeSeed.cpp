#include "tweaks.h"

#include <ll/api/memory/Hook.h>

#include <mc/network/packet/StartGamePacket.h>
#include <mc/world/level/LevelSettings.h>
#include <mc/world/level/LevelSeed64.h>

#include <MintVanilla.h>
#include <Config.h>

namespace mintvanilla::fakeseed {

LL_TYPE_INSTANCE_HOOK(
  FakeSeedHook,
  ll::memory::HookPriority::Normal,
  StartGamePacket,
  &StartGamePacket::$write,
  void,
  BinaryStream& bs
) {
  this->mSettings->mSeed->mValue = uint64_t(mintvanilla::MintVanilla::getInstance().getConfig().extras.seed);
  return origin(bs);
}

struct FakeSeed::Impl {
  ll::memory::HookRegistrar<FakeSeedHook> r;
};

void FakeSeed::call(bool enable) {
  if (enable) {
    if (!impl) impl = std::make_unique<Impl>();
  } else {
    impl.reset();
  }
}

FakeSeed::FakeSeed()  = default;
FakeSeed::~FakeSeed() = default;

} // namespace mintvanilla::allowclientresourcepack