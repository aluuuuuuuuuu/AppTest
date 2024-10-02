#include <Windows.h>
#include <tchar.h>

// �E�B���h�E�T�C�Y
const unsigned int window_width = 1280;
const unsigned int window_height = 720;

// �ʓ|�����Ǐ����Ȃ���΂����Ȃ��֐�
LRESULT WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	// �E�B���h�E���j�����ꂽ��Ă΂��
	if (msg == WM_DESTROY)
	{
		PostQuitMessage(0);	// OS�ɑ΂��āu�������̃A�v���͏I���Ɠ`����v
		return 0;
	}
	return DefWindowProc(hwnd, msg, wparam, lparam);	// ����̏������s��
}

// ���C���֐�
#ifdef _DEBUG
int main()
{
#else
int main()
{
#endif
	// �E�B���h�E�N���X�̐������o�^
	WNDCLASSEX w = {};

	w.cbSize = sizeof(WNDCLASSEX);
	w.lpfnWndProc = (WNDPROC)WindowProcedure;	// �R�[���o�b�N�֐�
	w.lpszClassName = _T("AppTest");	// �A�v���P�[�V�����N���X��

	RegisterClassEx(&w);	// �A�v���P�[�V�����N���X
	
	RECT wrc = { 0,0,window_width,window_height };	// �E�B���h�E�T�C�Y�����߂�

	// �֐����g���ăE�B���h�E�̃T�C�Y��␳����
	AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);

	// �E�B���h�E�I�u�W�F�N�g�̐���
	HWND hwnd = CreateWindow(w.lpszClassName,	// �N���X���w��
		_T("AppTest"),			// �^�C�g���o�[�̕���
		WS_OVERLAPPEDWINDOW,	// �^�C�g���o�[�Ƌ��E��������E�B���h�E
		CW_USEDEFAULT,			// �\��x���W��OS�ɂ��C��
		CW_USEDEFAULT,			// �\��y���W��OS�ɂ��C��
		wrc.right - wrc.left,	// �E�B���h�E��
		wrc.bottom - wrc.top,	// �E�B���h�E��
		nullptr,				// �e�E�B���h�E�n���h��
		nullptr,				// ���j���[�n���h��
		w.hInstance,			// �Ăяo���A�v���P�[�V�����n���h��
		nullptr);

	// �E�B���h�E�\��
	ShowWindow(hwnd, SW_SHOW);

	MSG msg = {};

	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}













		// �A�v���P�[�V�������I���Ƃ���message��WM_QUIT�ɂȂ�
		if (msg.message == WM_QUIT)
		{
			break;
		}
	}

	// �N���X�̓o�^����������
	UnregisterClass(w.lpszClassName, w.hInstance);


}