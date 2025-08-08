#pragma once

#include <ll/api/mod/NativeMod.h>
#include "Config.h"

namespace mintvanilla {

class MintVanilla {
public:
    static MintVanilla& getInstance();

    MintVanilla() : mSelf(*ll::mod::NativeMod::current()) {}

    [[nodiscard]] ll::mod::NativeMod& getSelf() const { return mSelf; }

    /// @return True if the mod is loaded successfully.
    bool load();

    /// @return True if the mod is enabled successfully.
    bool enable();

    /// @return True if the mod is disabled successfully.
    bool disable();

    /// @return True if the mod is unloaded successfully.
    bool unload();

    Config& getConfig();

private:
    ll::mod::NativeMod& mSelf;
    Config mConfig;
};

} // namespace mintvanilla