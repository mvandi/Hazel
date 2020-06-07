#pragma once

#include <array>
#include <string>

#include <glm/glm.hpp>

#include "Hazel/Core/Base.h"

namespace Hazel {

	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual uint32_t GetRendererID() const = 0;

		virtual void SetData(void* data, uint32_t size) = 0;

		virtual void Bind(uint32_t slot = 0) const = 0;

		virtual bool operator==(const Texture& other) const = 0;
	};

	using TexCoords = std::array<glm::vec2, 4>;

	class Texture2D : public Texture
	{
	public:
		virtual const TexCoords& GetTexCoords() const { return DefaultTexCoords; }
		
		static TexCoords CreateTexCoords(const glm::vec2& min, const glm::vec2& max);

		static Ref<Texture2D> Create(uint32_t width, uint32_t height);
		static Ref<Texture2D> Create(const std::string& path);
	public:
		static const TexCoords DefaultTexCoords;
	};

}