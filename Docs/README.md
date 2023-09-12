# 如何補題

## Zerotier

為提高安全性，彰中資訊社Judge需使用內網穿透的方式來連線。
而Zerotier即為一套能夠實現此類需求的軟體。

1. 首先，請先至[Zerotier 官方網站](https://www.zerotier.com/download/)下載安裝檔。
或者可以使用以下指令安裝：
```bash
winget install ZeroTier.ZeroTierOne
```

2. 在工作列系統匣加入資訊社網路，代碼如下：

```
abfd31bd47d62f91
```

或者，也可以使用指令(需要管理者權限)來加入：

```bash
zerotier-cli join abfd31bd47d62f91
```

## 使用競賽CMS系統

請事先安裝**Zerotier**

連線至 [192.168.194.225](http://192.168.194.225/) ，如果無法連線請確認已經加入彰中資訊社網路(CITRC_network)，並稍後再試。

帳號及密碼與比賽時相同。

## 使用CJ

請事先安裝**Zerotier**

連線至 [192.168.194.20](http://192.168.194.20/) ，如果無法連線請確認已經加入彰中資訊社網路(CITRC_network)，並稍後再試。

## 使用Codeforces

[直接使用此連結加入即可](https://codeforces.com/contestInvitation/2de9facc215a2cb24d859511b518ff2591ff41f3)

祝各位補題順利。
