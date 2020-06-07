#pragma once

#include "Texture.h"

namespace Hazel {

	class SubTexture2D : public Texture2D
	{
	public:
		SubTexture2D(const Ref<Texture2D>& texture, const glm::vec2& min, const glm::vec2& max);

		virtual uint32_t GetWidth() const override { return m_Width; }
		virtual uint32_t GetHeight() const override { return m_Height; }
		virtual uint32_t GetRendererID() const override { return m_Texture->GetRendererID(); }

		virtual void SetData(void* data, uint32_t size) override;

		virtual void Bind(uint32_t slot = 0) const override;

		virtual const TexCoords& GetTexCoords() const override { return m_TexCoords; }

		virtual bool operator==(const Texture& other) const override
		{
			return *m_Texture.get() == other;
		}

		static Ref<SubTexture2D> CreateFromCoords(const Ref<Texture2D>& texture, const glm::vec2& coords, const glm::vec2& cellSize, const glm::vec2& spriteSize = {1.0f, 1.0f});
	private:
		Ref<Texture2D> m_Texture;
		TexCoords m_TexCoords;

		int m_Width;
		int m_Height;
	};

}