# 備忘録

## コンパイル時よく使うオプション

|Option|Information|
|---|---|
|-o|実行ファイル名変更|
|-g|デバッグ用の実行ファイルを込めて作成|
|-O0|最適化を無効化(デバックの時重要)|

**例** :

    $ gcc -o culc -g -O0 ./file_enter/01_fileexchange.c

## gdbの使い方に参考にしたサイト

(敬称略、デバッガの使い方が初心者ながら少しだけわかりました。)

* [初めてのGDB - @ShikiSumiya](https://qiita.com/ShikiSumiya/items/a08363db88f21c81d351)
* [gcc+gdbによるプログラムのデバッグ - rat(法政大学情報科学部)](https://rat.cis.k.hosei.ac.jp/article/devel/debugongccgdb1.html)
* [gdbを使ってコアダンプの原因を解析 - けんつ](http://rabbitfoot141.hatenablog.com/entry/2016/11/14/153101)

## Gitの使い方で困惑したこと(不完全版)

    $ git pull

は魔法の言葉で、いままで何も考えなしに使って、リモートリポジトリから編集ファイルをダウンロードしていた。しかし、元のリポジトリの状態から手を少し加えると、このコマンドを与えたときに**競合**が発生。(当たり前なんだよなぁ…)

そこで、競合に初めて立ち向かったので記録を残しておく。

そもそも、上のコマンドはマージまで一緒にしてくれる、本当に魔術的な共有リポジトリのためのものなのだが、まとめてしまっているため途中で止まってくれないみたい？

なので、マージまではしないダウンロードをする。それが

    $ git fetch

である。このコマンドでとりあえずダウンロードする物はしてしまったみたい？

で、ここからログ解析+差分検証をして、確認する。

    $ git log HEAD..FETCH_HEAD
    $ git diff HEAD..FETCH_HEAD

ちょっと勉強不足だから、最後の部分の意味が分かりたい。
とりあえずこう打てば、リポジトリと手元のファイルの差分が理解できる。

こうやって、やっとマージする。

    $ git merge FETCH_HEAD

と打てば、例えば、差分の領域が次のように示される。

    <<<<<<< HEAD
    <div id="footer">contact : email.support@github.com</div>
    =======
    <div id="footer">
      please contact us at support@github.com
    </div>
    >>>>>>> iss53

↑のは [一例](https://git-scm.com/book/ja/v1/Git-%E3%81%AE%E3%83%96%E3%83%A9%E3%83%B3%E3%83%81%E6%A9%9F%E8%83%BD-%E3%83%96%E3%83%A9%E3%83%B3%E3%83%81%E3%81%A8%E3%83%9E%E3%83%BC%E3%82%B8%E3%81%AE%E5%9F%BA%E6%9C%AC) である。ここの<<<やら>>>やら===と一緒に、不要な部分を消せばよい。

<p><font size="3">VScodeは凄くて、ここをうまく色分けしてくれているので、間違えようが少ないのかもしれません。</font></p>

## コード書いてて詰まったところ

### ○ fgetsの困惑 (2018/6/7の日記)

普通文字列の型では

    char str[1000];

みたいな形で宣言できるが、次のような荒業

    char *str;

でも普通宣言できる。しかし、下のような宣言の仕方でfgetsに文字列を突っ込もうとした場合、セグフォが出てしまった。どうしろと。(実力不足なだけ)