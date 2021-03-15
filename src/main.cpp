#include "webkit.hpp"

int main() {
  Tag html("html");

  auto head = html.addChild(new Tag("head"));
  head->addChild(new Tag("title", "C++ Mexico"));
  head->addChild(new Tag("style", loadCss("test.css")));

  Tag body("body");
  html.addChild(&body);

  body
    .addAttr("style", R"(
      line-height: 1.4;
      font-size: 10pt;
      font-family: Lucida\ Console, monaco, monospace;
      margin: 1em auto;
      max-width: 1000px;
    )");

  body
    .addChild(new Tag("header"))
      ->addAttr("style", R"(
        padding-top: 10px;
        text-align: center;
      )")
      ->addChild(new Tag("strong", "C++ Mexico"))
        ->addAttr("style", R"(
          font-size: 26pt;
          font-weight: normal;
          color: black;
        )");

  auto center = body
    .addChild(new Tag("main"))
      ->addChild(new Tag("div"))
        ->addAttr("class", "p")
        ->addChild(new Tag("center"));

  center
    ->addChild(new Tag("img"))
      ->addAttr("src", "https://cpp.com.mx/images/logo.png");

  center
    ->addChild(new Tag("p", "Comunidad de C++ Mexico"));

  center
    ->addChild(new Tag("p", R"(<a href="https://twitter.com/cpp_mx">Twitter</a> / <a href="https://discord.gg/t53X2e8Mrz">Discord</a> / <a href="https://github.com/cppmexico">Github</a>)"));

  html.show();
}
