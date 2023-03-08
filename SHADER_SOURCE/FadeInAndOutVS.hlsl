#include "globals.hlsli"

struct VSIn
{
    float4 Pos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};

struct VSOut
{
    float4 Pos : POSITION;
    float4 Color : COLOR;
    float2 UV : TEXCOORD;
};

VSOut main(VSIn In)
{
    VSOut Out = (VSOut) 0.0f;
    
    float4 worldPosition = mul(In.Pos, world);
    float4 viewPosition = mul(worldPosition, view);
    float4 ProjPosition = mul(viewPosition, projection);
    
    Out.Pos = ProjPosition;
    Out.Color = In.Color;
    Out.UV = In.UV;

    return Out;
}