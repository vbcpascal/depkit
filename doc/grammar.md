# Grammar of DepKit

## Programs

```
<program> ::= <definitions> %% <dependencies> %% <requirements>
		
<definitions> ::= <definitions> <definition> | <empty>

<dependencies> ::= <dependencies> <dependency> | <empty>

<requirements> ::= <requirements> <requirement> | <empty>

<definition> ::= <package-identification> = <metadata>

<metadata> ::= ()

<dependency> ::= <name> : { <dep-body> }

<dep-body> ::= <require-list>? <depend-list>?

<require-list> ::= <require-clause> <require-list>

<require-clause> ::= require ( <property-expr> );

<depend-list> ::= <depend-clause> <depend-list>

<depend-clause> ::= <package-expr> | <if-package> | <if-else-package>



<package-identification> ::= <name> [ <property-list> ]

<property-list> ::= <property> ; <property-list> | <property>

<property> ::= <prop-name> : { <tok-list> }

<prop-name> ::= version | features | backends

<tok-list> ::= <string> , <tok-list> | <string>



<if-package> ::= if <property-expr> { <depend-clause> }

<if-else-package> ::= <if-package> else { <depend-clause> }

<property-expr> ::= <prop-expr-or>

<prop-expr-or> ::= <prop-expr-and> | <prop-expr-and> || <prop-expr-or>

<prop-expr-and> ::= <prop-expr-not> | <prop-expr-not> && <prop-expr-and>

<prop-expr-not> ::= <prop-expr-atom> | ! <prop-expr-not>

<prop-expr-atom> ::= 
		<prop-name> >= <string>
	| <prop-name> >  <string>
	| <prop-name> <= <string>
	| <prop-name> <  <string>
 	| <prop-name> == <string>
	| <prop-name> != <string>
	| <string> in <prop-name>
	| <string> not in <prop-name>

<package-expr> ::= <package-expr-or>

<package-expr-or> ::= <package-expr-and> | <package-expr-and> || <package-expr-or>

<package-expr-and> ::= <package-expr-not> | <package-expr-not> && <package-expr-and>

<package-expr-not> ::= <package-expr-atom> | ! <package-expr-not>

<package-expr-atom> ::= 
		<name>
	| <package-prop> >= <string>
	| <package-prop> >  <string>
	| <package-prop> <= <string>
	| <package-prop> <  <string>
	| <package-prop> == <string>
	| <package-prop> != <string>
	| <string> in <package-prop>
	| <string> not in <package-prop>

<package-prop> ::= <name> . <prop-name>

<requirement> ::= <package-identification>

```

## Keywords

```
version, feature, backend, in, not, if, else, require
```



