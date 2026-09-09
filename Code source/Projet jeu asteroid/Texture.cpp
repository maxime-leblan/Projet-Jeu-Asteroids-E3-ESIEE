#include "Texture.h"

Texture::Texture() {}

Texture::Texture(string pTextureStr)
{
    aTextureStr = pTextureStr;
    aId = G2D::initTextureFromString(aSize, pTextureStr);
}

void Texture::show(V2 pPosition, float pAngle=0) const
{
    G2D::drawRectWithTexture(aId, pPosition, aSize, pAngle);
}

V2 Texture::getSize() const
{
    return aSize;
}