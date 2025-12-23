#pragma once

#include <Rengine/Core/Types.hxx>
#include <string_view>

namespace Ren::AssetPipeline
{

using AssetID = UInt64;

// Inherit this class to create a new asset type.
class Asset
{
public:
    Asset() = default;
    virtual ~Asset();

    virtual std::string_view GetAssetTypeName() = 0;

    AssetID GetAssetID() const { return _assetID; }

private:
    AssetID _assetID;
    
    Byte* _rawAssetData;

    friend class AssetManager;
};

} // namespace Ren::AssetPipeline
