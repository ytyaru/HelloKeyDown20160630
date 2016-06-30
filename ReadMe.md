# このソフトウェアについて #

HelloKeyDown20160630は私個人が学習目的で作成したソフトウェアです。

C++/win32でWM_KEYDOWN, WM_KEYUP, メッセージを取得しました。
Spaceキーを押下すると表示が変ります。

# 開発環境 #

* Windows XP SP3
* C++/Win32
* Visual C++ 2010 Express

# イメージ #

![Spaceキー押下前](http://cdn-ak.f.st-hatena.com/images/fotolife/y/ytyaru/20160630/20160630165636.png)  
![Spaceキー押下後](http://cdn-ak.f.st-hatena.com/images/fotolife/y/ytyaru/20160630/20160630165750.png)  

# 問題 #

キーを押下している最中、画面がちらつきます。
ダブルバッファリングで対処する必要がありそう。

# ライセンス #

このソフトウェアはCC0ライセンスです。

[![CC0](http://i.creativecommons.org/p/zero/1.0/88x31.png "CC0")](http://creativecommons.org/publicdomain/zero/1.0/deed.ja)
