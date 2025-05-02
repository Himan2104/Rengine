#pragma once

#include <Rengine/Core/Definitions.hxx>
#include <map>
#include <string>

namespace Ren::AssetPipeline
{

using AssetID = UInt64;

class AssetBank final
{
public:
    AssetBank() = default;

private:
    std::map<AssetID, class IAsset*> _assetMapping;

#ifndef REN_AP_OPTIMIZE // Named Mappings shall only exist in unoptimized builds.
    std::map<std::string, AssetID> _assetNameMappings;
#endif
};

} // namespace Ren::AssetPipeline
