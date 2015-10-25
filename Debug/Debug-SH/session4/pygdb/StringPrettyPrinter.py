import gdb
import gdb.printing

class StdStringPrinter:
    def __init__(self, val):
        self.val = val

    def to_string(self):
        return self.val['_M_dataplus']['_M_p'].string()

def build_pretty_printer():
    pp = gdb.printing.RegexpCollectionPrettyPrinter("stl_printers")
    pp.add_printer("string_printer", "^std::basic_string<char,.*>$", StdStringPrinter)
    return pp

gdb.printing.register_pretty_printer(gdb.current_objfile(), build_pretty_printer())