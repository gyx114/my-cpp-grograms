#include <iostream>
#include <windows.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <audioclient.h>

// 链接必要的库
#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "oleaut32.lib")

/**
 * 获取当前系统主音量的百分比 (0~100)
 * 返回 -1 表示获取失败
 */
int GetSystemVolumePercent()
{
    HRESULT hr;

    // 初始化 COM
    hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    if (FAILED(hr))
        return -1;

    int volumePercent = -1;

    // 创建设备枚举器
    IMMDeviceEnumerator *pEnumerator = nullptr;
    hr = CoCreateInstance(
        __uuidof(MMDeviceEnumerator), nullptr,
        CLSCTX_ALL, __uuidof(IMMDeviceEnumerator),
        (void **)&pEnumerator);

    if (SUCCEEDED(hr))
    {
        // 获取默认音频输出设备（扬声器）
        IMMDevice *pDevice = nullptr;
        hr = pEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &pDevice);

        if (SUCCEEDED(hr))
        {
            // 激活音频端点音量接口
            IAudioEndpointVolume *pEndpointVolume = nullptr;
            hr = pDevice->Activate(__uuidof(IAudioEndpointVolume),
                                   CLSCTX_ALL, nullptr,
                                   (void **)&pEndpointVolume);

            if (SUCCEEDED(hr))
            {
                // 获取当前音量标量值 (0.0 ~ 1.0)
                float fVolume = 0.0f;
                hr = pEndpointVolume->GetMasterVolumeLevelScalar(&fVolume);

                if (SUCCEEDED(hr))
                {
                    // 转换为百分比 (0~100)
                    volumePercent = static_cast<int>(fVolume * 100.0f + 0.5f);
                    if (volumePercent > 100)
                        volumePercent = 100;
                    if (volumePercent < 0)
                        volumePercent = 0;
                }

                pEndpointVolume->Release();
            }
            pDevice->Release();
        }
        pEnumerator->Release();
    }

    CoUninitialize();
    return volumePercent;
}

int main()
{
    int vol = GetSystemVolumePercent();
    if (vol >= 0)
        std::cout << "当前系统音量: " << vol << "%" << std::endl;
    else
        std::cout << "获取系统音量失败！" << std::endl;

    return 0;
}
