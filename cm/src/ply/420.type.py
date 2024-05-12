"""  → , λ
S → T L ;    # L.t = T.t
T → INT      # T.t = INT
T → DOUBLE   # T.t = DOUBLE
L → a M      # type(a, L.t); M.t = L.t
M →  λ       #
M → , L      # L.t = M.t
"""
tokens = ('ID','DOUBLE', 'INT', 
  'COMMA', 'SEMI' )
t_DOUBLE     = r'\.double'
t_INT        = r'\.int'
t_ID         = r'[a-zA-Z_][a-zA-Z_0-9]*'
t_COMMA      = r'\,'
t_SEMI    = r'\;'

t_ignore = " \t"

def t_error(t):
  print("Illegal character '%s'" %
    t.value[0])
  t.lexer.skip(1)

import ply.lex as lex;lex.lex()
start = 'S'
ds1 = []
def p_S(p):
  'S : T L SEMI' # S → E
  print(p[1])
  print(ds1)
def p_Ttype(p):
  """T : INT
       | DOUBLE"""
  p[0] = p[1]
def p_id_m(p):
  'L : ID M' 
  ds1.append(p[1])
def p_m_empty(p):
  'M : '
  pass
def p_MLFcomma(p):
  'M : COMMA L'
  pass
def p_error(p):
  print("Syntax error at '%s'" % p)
import ply.yacc as yacc; yacc.yacc()
s = '.int a,b,c;'
yacc.parse(s)
