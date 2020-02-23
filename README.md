Wavefront Obj Writer
===

A simple Wavefront OBJ writer.


## 説明
プログラムによって3Dオブジェクトを効率的に作成することができる、C++用のヘッダーオンリーライブラリです。分割コンパイルやリンクは必要ありません。

## 使い方
自分のcppファイルと同じディレクトリに`obj.h`と`vector.h`を入れて、cppファイルの中に`#include "obj.h"`と記述すれば使えます。

```
project_folder
├ main.cpp
├ obj.h
└ vector.h  
```

例えば、もっとも基本的な四角ポリゴンを作るには以下のようにします。

```cpp
#include "obj.h"

int main(){
    Obj obj;
    obj.appendVertex(  0,   0, 0);
    obj.appendVertex(100,   0, 0);
    obj.appendVertex(100, 100, 0);
    obj.appendVertex(  0, 100, 0);
    obj.closeFace();

    obj.output("quad");
}
```

詳細なライブラリの使用方法は <a href="https://github.com/nishidate-yuki/WavefrontObjWriter/blob/master/Documentation.md"> Documentation.md </a> に記載しています。

## サンプル

単純なプリミティブだけでなく、再帰を利用すると面白い形状が簡単に作成できます。
いくつかのサンプルファイルを`samples`に入れてあります。
![all](https://user-images.githubusercontent.com/30839669/75106473-7485db00-5660-11ea-8462-c51af1e3875f.png)