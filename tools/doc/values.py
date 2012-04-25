#!/usr/bin/python
# -*- coding: utf-8 -*-
title =  'mocha ES Next Translator'
after_compilation = '変換後は以下のようになります。'
active_class = 'class="active"'
values = {
'nav.html' : {
        'index.html' : {
            'active_index' : active_class
            },
        'first_step_guide.html' : {
            'active_first_step' : active_class
            },
        'es_next_detail.html' : {
            'active_grammar' : active_class
            },
        'api_guide.html' : {
            'active_api' : active_class
            }
        },
'index.html' : {
        'ja' : {
            'hero_sub' : 'mochaはEcmascript262 5th edition 及び、現在策定中のEcmascript harmonyの文法とちょっとした拡張をブラウザで利用可能なjavascriptに変換するコンパイラです。',
            'sp_translate' : 'ES Nextからjavascriptへの変換',
            'sp_translate_sub' : 'ES Nextを使用して記述されたファイルをブラウザで実行可能なjavascriptへ変換します。',
            'sp_cmp' : '圧縮',
            'sp_cmp_sub' : '変換済みのjavascriptを圧縮します。変換から圧縮までをシームレスに行えるので他のツールを起動する必要がありません。',
            'sp_module' : 'ファイルのモジュール化',
            'sp_module_sub' : 'ES Nextの機能であるimport及び、module構文。、mochaの独自拡張を利用したファイルの読み込みによりモジュール化をサポートします。これらはコンパイル時に静的に結合されます',
            'sp_version' : '条件別コンパイル',
            'sp_version_sub' : 'コンパイラ命令としてversion演算子を導入しました。事前に定義したバージョン識別子の有無でコードブロックの削除が可能です。',
            'sp_error_handler' : 'デバッグ用エラーハンドラの挿入',
            'sp_error_handler_sub' : 'ファイルを結合した際に、エラーが起きた行数がわからなくなるのを避けるため、行数及び、ファイル名をスコープ、あるいはステートメント毎に挿入します。',
            'sp_test' : '外部テストツールとの連携',
            'sp_test_sub' : 'phantomjsなどのテスト用ツールを利用したテストも可能です。'
            },
        'en' : {
            'hero_sub' : 'mocha is the translator to translate the Ecmascript262 5th edition, the Ecmascript harmony that is now working out and, some extensions to a browser runnable javascript.',
            'sp_translate' : 'Converte ES Next to javascript.',
            'sp_translate_sub' : 'Translate files that written by ES Next to the browser executable javascript.',
            'sp_cmp' : 'The compress',
            'sp_cmp_sub' : 'The mocha compress a translated javascript, and this done by seamless. So don\'t need to execute other tools.',
            'sp_module' : 'modules',
            'sp_module_sub' : 'The mocha support modules, by the ES Next\'s \'import\' and \'module statement\' and mocha\'s @include extension. That combined at the compilation time.',
            'sp_version' : 'versions',
            'sp_version_sub' : 'The mocha has version operator, so you can delete code block from compiled file by the version identifier that defined before the compilation.',
            'sp_error_handler' : 'The Error handler insertion.',
            'sp_error_handler_sub' : 'To easy debug, the mocha insert file name and line numbers, per statement or scope.',
            'sp_test' : 'The test.',
            'sp_test_sub' : 'You can use the phantomjs or other test libraries.'
            }
        },
'es_next_detail.html' : {
        'ja' : {
            'class_title' : '現在策定されているプロポーサルではclassが組み込まれる予定です。
		class機能自体はfunctionの糖衣構文になります。',
            'class_imp_browsers' : '実装済み処理系 : 無し',
            'class_ex1_title' : 'まずは今までの書き方でクラスを生成してみます。',
            'class_ex1_comment1' : 'このクラスはTHREE.Meshを継承しています。',
            'class_ex1_comment2' : '親クラスのコンストラクタを呼び出します。',
            'class_ex1_comment3' : 'ecmascript5以降での継承です。',
            'class_ex1_comment4' : 'THREE.Mesh.prototypeを継承したprototypeオブジェクトを生成します。',
            'class_ex1_comment5' : '親クラスのupdateメソッドの呼び出し。',
            'class_ex2_title' : '次にES Nextで予定されているclassを使って書き換えてみます。',
            'class_ex2_comment1' : '継承を行うためにはclass \'drived\' extends \'super\'という構文を使う',
            'class_ex2_comment2' : 'superはコンストラクタ関数か、クラスである必要がある',
            'class_ex2_comment3' : '親クラスのコンストラクタを呼び出す。',
            'class_ex2_comment4' : 'THREE.Mesh.call(this, geometry, materials)に該当',
            'class_ex2_comment5' : 'publicなメンバはすべてpublic修飾子を宣言の前に付与する',
            'class_ex2_comment6' : '親クラスのメソッド呼び出し。',
            'class_ex2_commnet7' : 'THREE.Mesh.prototype.update.call(this)に該当',
            'class_ex3_title' : '次に基本的なクラスの構成要素の説明をします。',
            'class_ex3_comment1' : 'コンストラクタは以下のように定義します。',
            'class_ex3_comment2' : 'クラスのメンバはコンストラクタ内で指定します。'
            'class_ex3_comment3' : 'クラスのメソッドはpublicかprivateのアクセス修飾が可能です。',
            'class_ex3_comment4' : '指定しない場合はprivateになります。',
            'class_ex3_comment5' : '省略関数も利用可能です。',
            'class_ex3_comment6' : 'publicな関数以外のメンバはprototypenに設定され、',
            'class_ex3_comment7' : '全てのインスタンスで共通の値が使用されます。',
            'class_ex3_comment8' : 'constなメンバはコンストラクタか、定義時に初期化しなければ',
            'class_ex3_comment9' : '値の追加はできません。',
            'class_ex3_comment10' : 'static修飾が宣言されると変数はstaticな変数になります。',
            'class_ex3_comment11' : 'static修飾にはprivate,publicは設定できません。',
            'class_ex4_title' : after_compilation,
            'class_detail_title' : '詳細',
            'class_detail_sub' : 'mochaではclassはコンストラクタ関数と、プロトタイプの糖衣構文として機能します。なので、既存のjavascriptのクラスと100%の互換性を持っています。またクラスを使用することによるオーバーヘッドもできるだけ抑えてありますが、privateフィールドの実現のためにやや実行時にオーバーヘッドがあります。',
            'class_section1_title' : 'インターフェース',
            'class_section1_sub1' : """クラスを宣言します。class nameとbase class nameはjavascriptで使用可能な変数名を使用可能です。
		    const修飾子がついていた場合は、すべてのメンバが変更不可能になります。
		    継承の際にextendsを選ぶと、通常のプロトタイプの継承になります。prototypeを選ぶと、直接&lt;base class name or literal&gt;をprototypeとして使用します。""",
            'class_section1_sub2' : """コンストラクタを定義します。コンストラクタは必ずconstructorという関数名でなければなりません。
				  メンバ変数の初期化を行います。コンストラクタが定義されていなければ、mochaが自動で空のコンストラクタを生成します。""",
            'class_section1_sub3' : """メンバを定義します。public修飾子がついていた場合はメンバは外部からアクセス可能になります。
				  const修飾子がついていた場合は、メンバは変更不可能になります。
				  private修飾子がついていた場合は、外部からアクセス不可なメンバになります。
				  何も修飾子を付けなかった場合は、デフォルトでprivateになります。
				  static修飾子が宣言された場合はメンバはインスタンス無しにアクセス可能になりますが、static以外のメンバにはアクセス出来ません。
				  またstaticなメンバはprivate、publicといったアクセス修飾は現在は出来ません。""",
            'class_section1_sub4' : 'publicメンバにアクセスします。',
            'class_section1_sub5' : 'privateメンバにアクセスします。',
            'trait_title' : 'クラスの振る舞いのみを定義したオブジェクトです。',
            'trait_impl_sub' : '実装済み処理系 : 無し',
            'trait_ex1_title' : 'traitの定義は以下のように行います。',
            'trait_ex2_title' : after_compilation,
            'trait_detail_title' : '詳細',
            'trait_detail_sub1' : """クラスに対して振る舞いを注入します。traitはrequireプロパティを設定することで実装しなければならないメソッドを指定できます。
またmixin属性を設定することで、trait同士、あるいはclassとtraitを合成可能です。その際にmixin ... with &lt;method_name&gt; as &lt:new_name&gt;とすることでメソッド名の書き換えが可能です。またwithout属性を指定することで、特定のメソッドのmixinを無効化することが可能です。
public,privateなどの指定はclassを参照してください。""",
            'trait_interface_title' : 'インターフェース',
            'trait_interface_sub1' : 'traitを宣言します。',
            'destructuring_title' : '分割代入機能です。',
            'destructuring_impl_sub' : '実装済み処理系 : mozilla 1.6以降',
            'destructuring_ex1_title' : '配列',
            'destructuring_ex2_title' : after_compilation,
            'destructuring_ex3_title' : 'オブジェクト',
            'destructuring_ex4_title' : after_compilation,
            'destructuring_ex5_title' : '少々複雑な例',
            'destructuring_ex6_title' : after_compilation,
            'for_each_title' : 'for each構文です。',
            'for_each_impl_sub' : '実装済み処理系 : mozilla 1.6以降',
            'for_each_ex2_sub' : '変換後',
            'do_expression_title' : '簡易スコープです。',
            'do_expression_impl_sub' : '実装済み処理系 : なし',
            'do_expression_ex2_title' : '変換後',
            'short_function_title' : '関数の短縮構文です。',
            'short_function_impl_sub' : '実装済み処理系 : なし',
            'short_function_ex1_title' : '無名関数',
            'short_function_ex2_title' : after_compilation,
            'short_function_ex3_title' : '関数宣言',
            'short_function_ex4_title' : after_compilation,
            'short_function_ex5_title' : 'コンテキストの束縛',
            'short_function_ex6_title' : after_compilation,
            'import_title' : 'モジュールのインポート機能です。',
            'import_impl_sub' : '実装済み処理系 : なし',
            'import_ex1_title' : after_compilation,
            'import_detail' : '詳細',
            'import_detail_title1' : 'importのルール',
            'import_detail_sub1' : 'ファイルのインポートは以下のルールに沿って行われます。',
            'import_detail_sub2' : '記述',
            'import_detail_sub3' : '説明',
            'import_detail_sub4' : '現在のファイルがあるディレクトリから探します。',
            'import_detail_sub5' : 'ランタイムモジュール、あるいはoptionのmoduleDirプロパティから探します。',
            'module_title' : 'モジュール化機能です。',
            'module_impl_sub' : '実装済み処理系 : なし',
            'module_ex2_title' : after_compilation,
            'module_detail_title' : '詳細',
            'module_detail_sub1' : '各モジュールはファイルスコープ直下にしか置けません。モジュールに指定した名前が直接エクスポートされます。',
            'module_decl_title' : '宣言',
            'module_decl_sub1' : 'moduleを宣言します。moduleはネスト可能です。ネストした場合は親のモジュール以下に設定されます。',
            'module_decl_sub2' : '直接値をエクスポートします。この構文でモジュールを宣言すると、'='で割り当てた値がmoduleの値になります。',
            'let_expression_title' : '新しいスコープを生成します。',
            'let_expression_impl_sub' : '実装済み処理系 : mozilla1.7以降',
            'let_expression_detail' : '詳細',
            'let_expression_detail_sub1' : 'スコープを生成します。let式の入り口に定義した値はlet式内のスコープでのみ有効になります。',
            'object_literal_extras_title' : 'オブジェクトリテラルの拡張構文です。',
            'object_literal_impl_sub' : '実装済み処理系 : なし',
            'object_literal_ex1_title' : after_compilation,
            'data_structure_extras_title' : 'データ構造の追加構文です。',
            'data_structure_extras_impl_sub' : '実装済み処理系 : なし',
            'data_structure_detail_title' : '詳細',
            'data_structure_extras_detail_sub1' : 'tupleを生成します。tupleは配列に似た値の集合ですが、imutableな値であり、変更不可能です。',
            'data_structure_extras_detail_th1' : '名前',
            'data_structure_extras_detail_th2' : 'インターフェース',
            'data_structure_extras_detail_th3' : '説明',
            'data_structure_extras_detail_sub2' : '２つのtupleを比較します。',
            'data_structure_extras_detail_sub3' : '配列に変換します。',
            'data_structure_extras_detail_sub4' : 'tupleの長さを返します。',
            'data_structure_extras_detail_sub5' : 'オブジェクトに似た連想配列を生成しますが、imutableであり、変更できません。',
            'data_structure_extras_detail_sub6' : '現在recordには特定のメソッドはありません。',
            'generator_iterator_title' : 'コルーチンや、列挙子を定義する拡張です。',
            'generator_iterator_impl_sub' : '実装済み処理系 : なし',
            'generator_iterator_ex1_comment1' : '通常のjavascript',
            'generator_iterator_mdn' : 'MDNからの引用',
            'generator_iterator_mdn_sub1' : 'yield キーワードを含む関数がジェネレータです。これを呼ぶと、ジェネレータの仮引数は実引数と結び付きますが、本体は実際には評価されません。代わりにジェネレータ・イテレータが返ってきます。ジェネレータ・イテレータの next() メソッドを呼び出すたびに、繰り返しのアルゴリズムが 1 回ずつ実行されます。それぞれのステップでの値は、yield キーワードで指定された値です。yield をアルゴリズムの繰り返しの範囲を示すジェネレータ・イテレータ版の return だと考えましょう。毎回 next() を呼び出すたび、ジェネレータのコードは yield の次の文から再開します。
あなたはジェネレータ・イテレータを、その next() メソッドを繰り返し呼び出すことで、あなたが望んだ結果の状態にたどりつくまで反復させられます。この例では、私たちが欲しいだけの結果を手に入れるまで g.next() を呼び出し続けることで、私たちはどれだけでも多くのフィボナッチ数を得ることができます。',
            'generator_iterator_mdn_link1' : 'https://developer.mozilla.org/ja/New_in_JavaScript_1.7#.E3.82.B8.E3.82.A7.E3.83.8D.E3.83.AC.E3.83.BC.E3.82.BF',
            'generator_iterator_mdn_sub2' : '簡単に説明すると関数をyieldキーワードの位置で一時停止し、二回目以降はその場所から実行を再開します。またnextだけではなく、yieldに対して、値を与えられるsendメソッドもあります。',
            'generator_iterator_mdn_sub3' : '一度 next() メソッドを呼び出してジェネレータをスタートさせると、与えた特定の値を最後の yield の結果として扱わせる send() を使うことができます。その際ジェネレータはその次の yield のオペランドを返します。
ジェネレータを勝手な時点から始めることはできません。特定の値を send() する前に必ず next() でジェネレータをスタートさせなければなりません。',
            'generator_iterator_mdn_link2' : 'https://developer.mozilla.org/ja/New_in_JavaScript_1.7#.E3.82.B8.E3.82.A7.E3.83.8D.E3.83.AC.E3.83.BC.E3.82.BF',
            'generator_iterator_mdn_sub4' : 'sendの例'
            }
}
}
