17. 自動的に生成される特殊メンバ関数を理解する
========================================================

特殊メンバ関数とは、C++が自ら生成するメンバ関数を意味し、下記が存在する

.. list-table::
   :header-rows: 1
   :stub-columns: 1



.. list-table::
   :header-rows: 1
   :stub-columns: 1
   :widths: 10, 20, 30

   * - 説明
     - シグネチャ
     - 備考
   * - デフォルトコンストラクタ
     - .. literalinclude:: src/003_default_constructore_signature.cpp
        :emphasize-lines: 2
     - | C++11以前から
       | コンストラクタを宣言していない場合に生成される
   * - デストラクタ
     - .. literalinclude:: src/002_default_destructore_signature.cpp
        :emphasize-lines: 2
     - | C++11以前から
       | 明示的に宣言していないが、コードでは使用している場合に生成される
       | 仮想デストラクタを持つクラスを継承していない場合は、非仮想関数となる(virtual が付かない)
   * - コピーコンストラクタ
     - .. literalinclude:: src/004_default_copy_constructor_signature.cpp
        :emphasize-lines: 2
     - | C++11以前から
       | 明示的に宣言していないが、コードでは使用している場合に生成される
   * - コピー代入演算子
     - .. literalinclude:: src/005_default_copy_operator_signature.cpp
        :emphasize-lines: 2
     - | C++11以前から
       | 明示的に宣言していないが、コードでは使用している場合に生成される
   * - ムーブコンストラクタ
     - .. literalinclude:: src/006_default_move_constructor_signature.cpp
        :emphasize-lines: 2
     - C++11から
   * - ムーブ代入演算子
     - .. literalinclude:: src/007_default_move_operator_signature.cpp
        :emphasize-lines: 2
     - C++11から


３関数同時ルール : コピーコンストラクタ・コピー代入演算子・デストラクタ のいずれか一つでも宣言する場合は、この３つ全て宣言するべきである というルール。


| **多態な基底クラスを使用した際の注意**

.. literalinclude:: src/008_sample_default_destructor.cpp
 :language: cpp
 :emphasize-lines: 6, 7, 9, 10


.. note::

    * ムーブ演算は、ムーブ演算・コピー演算・デストラクタのいずれも明示的に宣言していないクラスに対してのみ生成される
    * コピーコンストラクタは、ムーブ演算を宣言した場合には「= delete」される。
    * コピー代入演算は、ムーブ演算を宣言した場合には「= delete」される。
    * デストラクタを明示的に宣言したクラスに対するコピー演算の自動生成は非推奨
    * テンプレートメンバ関数が特殊メンバ関数の生成を抑制することはない。

