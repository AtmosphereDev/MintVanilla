#include "tweaks.h"

#include <ll/api/memory/Hook.h>

#include <mc/network/packet/ResourcePacksInfoPacket.h>

#include <MintVanilla.h>
#include <Config.h>

namespace mintvanilla::allowclientresourcepack {

LL_TYPE_INSTANCE_HOOK(
  ResourcePacksPacketHook,
  ll::memory::HookPriority::Normal,
  ResourcePacksInfoPacket,
  &ResourcePacksInfoPacket::$write,
  void,
  BinaryStream& bs
) {
  this->mData->mResourcePackRequired = true;
  return origin(bs);
}

struct AllowClientResourcePack::Impl {
  ll::memory::HookRegistrar<ResourcePacksPacketHook> r;
};

void AllowClientResourcePack::call(bool enable) {
  if (enable) {
    if (!impl) impl = std::make_unique<Impl>();
  } else {
    impl.reset();
  }
}

AllowClientResourcePack::AllowClientResourcePack()  = default;
AllowClientResourcePack::~AllowClientResourcePack() = default;

} // namespace mintvanilla::allowclientresourcepack