#include "MintVanilla.h"

#include <iostream>
#include <vector>
#include <string>

#include <ll/api/mod/RegisterHelper.h>
#include <ll/api/Config.h>
#include <ll/api/memory/Hook.h>
#include <ll/api/memory/Memory.h>

namespace mintvanilla {
namespace command {
  extern void registerRestartCommand();
  extern void registerTpsCommand();
}

MintVanilla& MintVanilla::getInstance() {
  static MintVanilla instance;
  return instance;
}

Config& MintVanilla::getConfig() { return mConfig; }

bool MintVanilla::load() {
  const auto& configFilePath = getSelf().getConfigDir() / "config.json";
  if (!ll::config::loadConfig(mConfig, configFilePath)) {
    getSelf().getLogger().warn("Cannot load configurations from {}", configFilePath);
    getSelf().getLogger().info("Saving default configurations");

    if (!ll::config::saveConfig(mConfig, configFilePath)) {
      mSelf.getLogger().error("Cannot save default configurations to {}", configFilePath);
    }
  }
  mSelf.getLogger().info("Loaded!");
  return true;
}

bool MintVanilla::enable() {
  if (getConfig().commands.restartCommand) {
    command::registerRestartCommand();
  }
  if (getConfig().commands.tpsCommand) {
    command::registerTpsCommand();
  }
  mSelf.getLogger().info("Enabled!");
  return true;
}

bool MintVanilla::disable() {
  mSelf.getLogger().info("Disabled!");
  return true;
}

bool MintVanilla::unload() {
  return true;
}

} // namespace mintvanilla

LL_REGISTER_MOD(mintvanilla::MintVanilla, mintvanilla::MintVanilla::getInstance());