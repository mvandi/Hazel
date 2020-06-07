#include "hzpch.h"
#include "Hazel/Renderer/Texture.h"

#include "Hazel/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLTexture.h"

namespace Hazel {

	const TexCoords Texture2D::DefaultTexCoords = Texture2D::CreateTexCoords({ 0.0f, 0.0f }, { 1.0f, 1.0f });

	TexCoords Texture2D::CreateTexCoords(const glm::vec2& min, const glm::vec2& max)
	{
		return {
			glm::vec2(min.x, min.y),
			glm::vec2(max.x, min.y),
			glm::vec2(max.x, max.y),
			glm::vec2(min.x, max.y)
		};
	}

	Ref<Texture2D> Texture2D::Create(uint32_t width, uint32_t height)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(width, height);
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Texture2D> Texture2D::Create(const std::string& path)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    HZ_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(path);
		}

		HZ_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}