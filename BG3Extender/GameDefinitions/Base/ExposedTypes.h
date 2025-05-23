#pragma once

#include <GameDefinitions/TranslatedString.h>

BEGIN_SE()

struct GameTime
{
    double Time{ 0 };
    float DeltaTime{ 0 };
    int32_t Ticks{ 0 };
    double Unknown{ 0 };
};

struct ActionOriginator
{
    Guid ActionGuid;
    FixedString PassiveId;
    FixedString StatusId;
    FixedString InterruptId;
    bool CanApplyConcentration{ false };
};

struct SpellMetaId
{
    FixedString OriginatorPrototype;
    uint8_t _Pad[4];
    SpellSourceType SourceType{ SpellSourceType::Sentinel };
    Guid Source;
    Guid ProgressionSource;
};

struct SpellId : public SpellMetaId
{
    FixedString Prototype;

    inline bool operator == (SpellId const& o) const
    {
        return
            OriginatorPrototype == o.OriginatorPrototype
            && SourceType == o.SourceType
            && Source == o.Source
            && ProgressionSource == o.ProgressionSource
            && Prototype == o.Prototype;
    }
};

template <>
inline uint64_t HashMapHash<SpellId>(SpellId const& v)
{
    return HashMulti(v.ProgressionSource, v.SourceType, v.Prototype, v.OriginatorPrototype);
}

struct SpellIdWithPrototype : public SpellId
{
    stats::SpellPrototype* SpellProto{ nullptr };
    std::optional<Guid> SpellCastSource;
};

struct DamagePair
{
    int32_t Amount;
    DamageType DamageType;
};

struct RollDefinition
{
    DiceSizeId DiceValue;
    uint8_t AmountOfDices;
    int DiceAdditionalValue;
    [[bg3::legacy(field_8)]] bool DiceNegative;
};

struct BoostParameters
{
    FixedString Boost;
    FixedString Params;
    FixedString Params2;
};

struct BoostSource
{
    BoostSourceType Type;
    FixedString Cause;
    EntityHandle Entity;
    ComponentHandle Status;
};

struct BoostDescription
{
    FixedString field_0;
    FixedString field_4;
    FixedString field_8;
};

struct ResourceRollDefinition
{
    Guid field_0;
    uint8_t field_10;
};

struct NavigationTargetInfo
{
    glm::vec3 Position;
    float CloseEnoughMin;
    float CloseEnoughMax;
    float CloseEnoughFloor;
    float CloseEnoughCeiling;
    int CloseEnoughPreference;
    EntityHandle TargetHandle;
    Array<EntityHandle> IgnoreEntities;
    uint32_t AiTargetCheck;
    uint16_t CoverFlags;
    bool AddSourceBoundsToMargin;
    bool field_3F;
    bool AvoidSurfaces;
    bool IsAvoidingObstacles;
    bool IsPreciseItemInteraction;
    EntityHandle PickupEntity;
    std::optional<glm::vec3> CharacterPositionOverride;
    uint8_t WeightFuncType;
};

struct PathSettings
{
    uint8_t PathClimbingMode;
    uint8_t PathDroppingMode;
    std::variant<uint8_t, float> Speed;
    bool HasSmoothingNodes;
    bool HasSpliningNodes;
    bool HasTurningNodes;
};

struct TextLine : TranslatedString
{
    bool field_10{ false };
};

END_SE()


BEGIN_NS(navigation)

struct TargetInfo
{
    glm::vec3 Position;
    float TargetRadius;
    float SpellRange;
    float TargetFloor;
    float TargetCeiling;
    int CloseEnoughPreference;
    EntityHandle InteractionTarget;
    Array<EntityHandle> InteractionTargets;
    int Type;
    uint16_t CoverFlags;
    bool AddSourceBoundsToMargin;
    bool field_3F;
    bool SurfaceAvoidance;
    bool IsAvoidingObstacles;
    bool IsPreciseItemInteraction;
    EntityHandle PickupEntity;
    std::optional<glm::vec3> PickupPosition;
    uint8_t WeightFuncType;
};

END_NS()
