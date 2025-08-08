#pragma once

#include <memory>

namespace mintvanilla {

namespace allowclientresourcepack {
struct AllowClientResourcePack {
    struct Impl;
    std::unique_ptr<Impl> impl;

    void call(bool);
    AllowClientResourcePack();
    ~AllowClientResourcePack();
};
} // namespace allowclientresourcepack

namespace fakeseed {
struct FakeSeed {
    struct Impl;
    std::unique_ptr<Impl> impl;

    void call(bool);
    FakeSeed();
    ~FakeSeed();
};
} // namespace fakeseed

namespace forcetrustedskin {
struct ForceTrustedSkin {
    struct Impl;
    std::unique_ptr<Impl> impl;

    void call(bool);
    ForceTrustedSkin();
    ~ForceTrustedSkin();
};
} // namespace forcetrustedskin

namespace hideoperator {
struct HideOperator {
    struct Impl;
    std::unique_ptr<Impl> impl;

    void call(bool);
    HideOperator();
    ~HideOperator();
};
} // namespace hideoperator

} // namespace mintvanilla