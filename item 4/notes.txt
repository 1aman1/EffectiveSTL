
Call empty instead of checking size() against zero.

%% GIST - HEADLINE

• ` if ( c.empty() ) ` instead of ` if ( c.size() == 0 ) `

• make it a habit because empty maybe implemented as an inline in different category of containers, it still fundamentlly relies on what container it is.

• on the same note, if a list has to check size() == 0, it will turn to a linear time call.