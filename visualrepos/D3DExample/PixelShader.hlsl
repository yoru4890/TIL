Texture2D ShaderTexture;

SamplerState Sampler
{
    AddressU = Wrap;
    AddressV = Wrap;
    Filter = MIN_MAG_MIP_LINEAR;
};

float4 main(float4 position : SV_POSITION, float2 tex : TEXCOORD0) : SV_TARGET
{
    float4 result = ShaderTexture.Sample(Sampler, tex);
    
    //float gray = (result[0]*0.2989 + result[1]*0.5870 + result[2]*0.1140);
    
    //result[0] = result[1] = result[2] = gray;
    
    //if (result[0] > 0.6f)
    //{
    //    result[0] = result[1] = result[2] = 1.0f;
    //}
    //else
    //{
    //    result[0] = result[1] = result[2] = 0.0f;
    //}
    
    
    return result;
}