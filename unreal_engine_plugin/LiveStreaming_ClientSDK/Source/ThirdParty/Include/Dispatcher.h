#pragma once

/// <summary>
/// .net��Dispatcher���Ăяo�����߂̐ݒ�
/// </summary>
namespace Dispatcher
{
	/// <summary>
	/// Dispatcher�ŏ��������Action�N���X�i�p������Exec����������j
	/// </summary>
	class Action
	{
	public:
		/// <summary>
		/// �f�X�g���N�^�i�K�v�ɉ����Čp�����Ĕj���������L�q����j
		/// </summary>
		virtual ~Action() {};
		/// <summary>
		/// Dispatcher�ŏ������������e���p�����Ď�������
		/// </summary>
		virtual void Exec() = 0;
	};
	
	/// <summary>
	/// Dispatcher�ŏ��������D�揇��
	/// </summary>
	enum class Priority
	{
		Invalid = -1, // �����l
		Inactive = 0, // ��������Ȃ�
		SystemIdle,
		ApplicationIdle,
		ContextIdle,
		Background,
		Input,
		Loaded,
		Render,
		DataBind,
		Normal,
		Send,
	};
};