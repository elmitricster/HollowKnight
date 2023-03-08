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

float4 main(VSOut In) : SV_Target
{
    float4 color = { 0.0f, 0.0f, 0.0f, 1.0f };
    
    if(cb16_bTextureType == 1)
        color = defaultTexture.Sample(pointSampler, In.UV);
    
    float alpha;
    
    if (cb16_bTextureType == 0)
    {
        alpha = saturate(1 - (cb16_fValue));
    }
    else if (cb16_bTextureType == 1)
    {
        alpha = saturate(0 + (cb16_fValue));
    }
    
    return color * alpha;
}