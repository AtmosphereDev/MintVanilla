#include "tweaks.h"

#include <ll/api/memory/Hook.h>

#include <mc/network/packet/UpdateAbilitiesPacket.h>
#include <mc/world/actor/SerializedAbilitiesData.h>

#include <MintVanilla.h>
#include <Config.h>

namespace mintvanilla::hideoperator {

LL_TYPE_INSTANCE_HOOK(
  UpdateAbilitiesPacketWriteHook,
  ll::memory::HookPriority::Normal,
  UpdateAbilitiesPacket,
  &UpdateAbilitiesPacket::$write,
  void,
  BinaryStream& bs
) {
  if (this->mData->mPlayerPermissions == PlayerPermissionLevel::Operator) {
    this->mData->mPlayerPermissions = PlayerPermissionLevel::Member;
  }
  return origin(bs);
}

struct HideOperator::Impl {
  ll::memory::HookRegistrar<UpdateAbilitiesPacketWriteHook> r;
};

void HideOperator::call(bool enable) {
  if (enable) {
    if (!impl) impl = std::make_unique<Impl>();
  } else {
    impl.reset();
  }
}

HideOperator::HideOperator()  = default;
HideOperator::~HideOperator() = default;

} // namespace mintvanilla::hideoperator