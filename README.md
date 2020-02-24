Wavefront Obj Writer
===

## Description
This is header-only library for C ++ that can efficiently create 3D objects by code. 

プログラムによって3Dオブジェクトを効率的に作成することができるC++用のヘッダーオンリーライブラリです。分割コンパイルやリンクは必要ありません。


## Usage
You can use this library by putting `obj.h` and `vector.h` in the directory where your cpp file is located.

自分のcppファイルと同じディレクトリに`obj.h`と`vector.h`を入れて、cppファイルの中に`#include "obj.h"`と記述すれば使えます。


```
project_folder
├ main.cpp
├ obj.h
└ vector.h  
```

You can create a quad by writing as follows.

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

Please see <a href="https://github.com/nishidate-yuki/WavefrontObjWriter/blob/master/Documentation.md"> Documentation.md </a> about a detailed usage of the library.

詳細なライブラリの使用方法は <a href="https://github.com/nishidate-yuki/WavefrontObjWriter/blob/master/Documentation.md"> Documentation.md </a> に記載しています。

## Sample
With recursive function, you can easily create interesting shapes.
Some sample files are included in `samples` directory.

再帰を利用すると、単純なプリミティブだけでなく面白い形状が簡単に作成できます。
いくつかのサンプルファイルを`samples`に入れてあります。

![all2](https://user-images.githubusercontent.com/30839669/75126036-78b30680-56fb-11ea-9990-1eb6aa1936de.png)