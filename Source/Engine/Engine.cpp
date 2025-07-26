#include "Engine.h"
#include "Renderer/Renderer.h"
#include "Audio/AudioSystem.h"
#include "Input/InputSystem.h"
#pragma once

namespace piMath {

	Engine& GetEngine()
	{
		static Engine engine;
		return engine;
	}

	void piMath::Engine::Update()
	{
		m_time.Tick();
		m_input->Update();
		m_audio->Update();
	}

	bool piMath::Engine::Initialize()
	{
		m_renderer = std::make_unique<piMath::Renderer>();
		m_renderer->Initialize();
		m_renderer->CreateWindow("Game project", 1280, 1024);

		m_input = std::make_unique<piMath::InputSystem>();
		m_input->Initialize();

		m_audio = std::make_unique<piMath::AudioSystem>();
		m_audio->Initialize();

		

		return true;
	}

	void piMath::Engine::Shutdown()
	{
		m_audio->Shutdown();
		m_input->Shutdown();
		m_renderer->Shutdown();
	}
}
