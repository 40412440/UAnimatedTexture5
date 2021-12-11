/**
 * Copyright 2019 Neil Fang. All Rights Reserved.
 *
 * Animated Texture from GIF file
 *
 * Created by Neil Fang
 * GitHub: https://github.com/neil3d/UAnimatedTexture5
 *
*/

#pragma once

#include "CoreMinimal.h"
#include "AnimatedTextureDecoder.h"
#include "libwebp/src/webp/decode.h"
#include "libwebp/src/webp/demux.h"

/**
* @see https://developers.google.com/speed/webp/docs/api
*/
class FWebpDecoder : public FAnimatedTextureDecoder
{
public:
	FWebpDecoder() = default;
	virtual ~FWebpDecoder();

	virtual bool LoadFromMemory(const uint8* InBuffer, uint32 InBufferSize) override;
	virtual void Close() override;

	virtual uint32 PlayFrame(uint32 DefaultFrameDelay, bool bLooping) override;
	virtual void Reset() override;

	virtual uint32 GetWidth() const override { return Width; }
	virtual uint32 GetHeight() const override { return Height; }
	virtual const FColor* GetFrameBuffer() const override;

	virtual uint32 GetDuration(uint32 DefaultFrameDelay) const override;
	virtual bool SupportsTransparency() const override;

private:
	int Width = 0;
	int Height = 0;
	WebPAnimDecoder* Decoder = nullptr;
};