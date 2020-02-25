
## 基本

四角ポリゴンを作るには以下のようにします。

```cpp
#include "obj.h"

int main(){
    wow::Obj obj;
    obj.appendVertex(  0,   0, 0);
    obj.appendVertex(100,   0, 0);
    obj.appendVertex(100, 100, 0);
    obj.appendVertex(  0, 100, 0);

    obj.closeFace();
    
    obj.output("quad");
}

```

- appendVertex()は3次元座標を与えるとVertexを生成してobjに追加します。
- closeFace()は直近に追加したVertexを用いてポリゴンを生成してobjに追加します。ポリゴンは必ず3または4頂点で構成される必要があります。
- output()はオブジェクトを`.obj`形式で書き出します。その際オブジェクトの名前を与える必要があります。


## NormalとTexture Coordinates

Vertexクラスを使用すると、法線またはテクスチャ座標を設定することもできます。

```cpp
wow::Obj obj;

wow::Vertex vertex;
vertex.setPosition(0, 0, 0);
vertex.setNormal(0, 0, -1);
vertex.setTexCoord(0, 0);
obj.appendVertex(vertex);

obj.enableTextureCoordinates(); // テクスチャ座標を有効化
obj.enableNormal();             // 法線を有効化
obj.output("point");
```

- vertexに対して`set~~()`で情報を追加できます。
- objを書き出す前には`enable~~()`で法線またはテクスチャ座標を有効にする必要があります。



## Faceの作り方
ポリゴンを作るには先述の`closeFace()`を利用する他にインデックスを指定する方法もあります。

```cpp
#include "obj.h"

int main(){
    wow::Obj obj;
    obj.appendVertex(  0,   0, 0);
    obj.appendVertex(100,   0, 0);
    obj.appendVertex(100, 100, 0);
    obj.appendVertex(  0, 100, 0);

    // obj.closeFace();
    obj.appendFace(0, 1, 2, 3);
    
    obj.output("quad");
}
```

- `appendFace()`にはインデックスを3つまたは4つ指定する必要があります。

## Lineオブジェクト
ポリゴンオブジェクトだけでなくラインオブジェクトにも対応しています。

例えば、単純な円を作成するには以下のように記述できます。

```cpp
#include "obj.h"
LineObj createCircle(float rad = 100, int segments = 128){
    LineObj obj;

    for(int i=0; i<segments; i++){
        float x = cos(float(i)/segments * 2*PI) * rad;
        float y = sin(float(i)/segments * 2*PI) * rad;
        obj.appendVertex(x, y, 0);
    }

    obj.closeLine();
    return obj;
}
```

- `closeLine()`はappendしたVertexをLineとして繋げます。その際に最後に追加したVertexと最初のVertexを繋げることでLineを閉じます。
- `finishLine()`とすればLineを閉じずに作成できます。