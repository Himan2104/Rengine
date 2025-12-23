#pragma once

#include "Rengine/Core/Array.hxx"
#include <Rengine/AssetPipeline/Asset.hxx>
#include <Rengine/Core/Types.hxx>
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
    Bool LoadManifest();

private:
    std::map<AssetID, Asset*> _assetMapping;

    DynamicArray<Asset> _assetChunk;

#ifndef REN_AP_OPTIMIZE // Named Mappings shall only exist in unoptimized builds.
    std::map<std::string, AssetID> _assetNameMappings;
#endif
};

} // namespace Ren::AssetPipeline
