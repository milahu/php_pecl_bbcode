#include <stdio.h>
#include <stdlib.h>

#include <bbcode2.h>

void main() {
	bbcode_parser_p parser = bbcode_parser_create();
	bbcode_parser_set_flags(parser, BBCODE_AUTO_CORRECT|BBCODE_ARG_DOUBLE_QUOTE|BBCODE_ARG_SINGLE_QUOTE);

    // based on https://github.com/pegelfDE/pegelcraft.de/blob/master/lib/bbcodes.php

    bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_NOARG,
        0,
        "b", 1, // tag
        "<b>", 3, // open_tag
        "</b>", 4, // close_tag
        "", 0, // default_arg
        "all", 3, // parent_list
        "all", 3, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_NOARG,
        0,
        "i", 1,
        "<i>", 3,
        "</i>", 4,
        "", 0, // default_arg
        "all", 3, // parent_list
        "all", 3, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_NOARG,
        0,
        "u", 1,
        "<u>", 3,
        "</u>", 4,
        "", 0, // default_arg
        "all", 3, // parent_list
        "all", 3, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_OPTARG,
        0,
        "url", 3,
        "<a href=\"{PARAM}\">", 18,
        "</a>", 4,
        "{CONTENT}", 9,
        "all", 3,
        "b,i", 3,
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_NOARG,
        0,
        "img", 3,
        "<img src=\"", 10,
        "\">", 2,
        "", 0, // default_arg
        "all", 3, // parent_list
        "all", 3, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_ARG,
        0,
        "size", 4,
        "<span style=\"font-size: {PARAM}px;\">", 36,
        "</span>", 7,
        "", 0, // default_arg
        "all", 3, // parent_list
        "all", 3, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_ARG,
        0,
        "align", 5,
        "<div class=\"text-{PARAM}\">", 26,
        "</div>", 6,
        "", 0, // default_arg
        "all", 3, // parent_list
        "all", 3, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_ARG,
        0,
        "wise", 4,
        "<div class=\"alert alert-{PARAM}\">", 33,
        "</div>", 6,
        "", 0, // default_arg
        "all", 3, // parent_list
        "all", 3, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

    // TODO [list=1] -> <ol>
	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_NOARG,
        0,
        "list", 4,
        "<ul>", 4,
        "</ul>", 5,
        "", 0, // default_arg
        "all", 3, // parent_list
        "*", 1, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_NOARG,
        0,
        "*", 1,
        "<li>", 4,
        "</li>", 5,
        "", 0, // default_arg
        "list", 4, // parent_list
        "all", 3, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	bbcode_parser_add_ruleset(
        parser,
        BBCODE_TYPE_NOARG,
        0,
        "align", 5,
        "<pre><code>", 11,
        "</code></pre>", 13,
        "", 0, // default_arg
        "all", 3, // parent_list
        "all", 3, // child_list
        0, // max_parsed
        NULL, // param_handling_func
        NULL, // content_handling_func
        NULL, // param_handling_func_data
        NULL // content_handling_func_data
    );

	char *ret;
	int i;
	char *string="[b], [i]Test, [/b] [url='http://www.bmco.be/']Coucou[/url][/i] Blug";
	bbcode_parser_add_smiley(parser, ":D", 2, "replaced", 8);
	ret = bbcode_parse(parser, string, strlen(string), &i);
	bbcode_parser_free(parser);
	printf("%s", ret);
	free(ret);
	printf("\n");
}
