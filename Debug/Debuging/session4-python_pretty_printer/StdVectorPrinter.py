import gdb
import gdb.printing

class StdVectorPrinter:
    "Print a std::vector"

    def __init__(self, val):
        self.val = val


    def to_string(self):
        start = self.val['_M_impl']['_M_start']
        finish = self.val['_M_impl']['_M_finish']
        end = self.val['_M_impl']['_M_end_of_storage']

        item = start
        while item != finish:
            elt = item.dereference()
            print elt
            item = item + 1


def build_pretty_printer():
    pp = gdb.printing.RegexpCollectionPrettyPrinter("stl_printers")
    pp.add_printer("vector_printer", "^std::vector<.*>$", StdVectorPrinter)
    return pp

gdb.printing.register_pretty_printer(gdb.current_objfile(), build_pretty_printer())

