40. 並行処理にはstd::atomic を、特殊メモリには volatile を用いる
========================================================

| コンパイラの最適化の例

| *最適化前：*

.. code-block:: c

    auto y = x;     // read x
    y = x;          // read x again
    x = 10;         // write x
    x = 20;         // write x again


| *最適化後：*

.. code-block:: c

    auto y = x;     // read x
    x = 20;         // write x

| volatile を使用すると、上記のような最適化を抑止できる

.. note::
    * std::atomic は、mutex を用いず複数スレッドからアクセスできるデータを表現する。 傾向ソフトウェアを開発するための道具である。
    * volatile は、読み取り/ 書き込みを最適化すべきではないメモリを表現する。特殊なメモリを操作するための道具である。

