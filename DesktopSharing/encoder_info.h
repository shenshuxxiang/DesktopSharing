#ifndef _ENCODER_INFO_H
#define _ENCODER_INFO_H

#include <cstdint>
#include <string>
#include <dxgi.h>
#include <d3d11.h>

struct encoder_config
{
	uint32_t width;
	uint32_t height;
	uint32_t framerate;
	uint32_t gop;
	std::string codec;  // "h264" "hevc"
	DXGI_FORMAT format; // DXGI_FORMAT_NV12 DXGI_FORMAT_B8G8R8A8_UNORM
};

struct encoder_info
{
	bool (*is_supported)(void);
	void* (*create)(void);
	void (*destroy)(void *encoder_data);
	bool (*init)(void *encoder_data, void *encoder_config);
	int (*encode_texture)(void *nvenc_data, ID3D11Texture2D *texture, uint8_t* buf, uint32_t maxBufSize);
};

#endif