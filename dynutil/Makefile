# pick up INCLUDE_DEST
TO_CORE = ..

include ../make.config

LOCAL_INCLUDE_DEST = $(INCLUDE_DEST)
CP = cp
CP_DIR = cp -r

TO_INC = h
PUBLIC_H = Annotatable.h \
	dyntypes.h \
	util.h \
	Serialization.h \
	Graph.h \
	Edge.h \
	Node.h \
	dyn_regs.h \
	stl_utils.h \
	SymReader.h \
	AST.h \
	ProcReader.h \
        IBSTree.h \
        entryIDs.h

INSTALL_TARGETS = $(addprefix $(TO_INC)/, $(PUBLIC_H))
world:
	@echo Nothing to be done for build

install: $(INSTALL_TARGETS)
	mkdir -p $(DESTDIR)$(LOCAL_INCLUDE_DEST)
	$(CP) $(INSTALL_TARGETS) $(DESTDIR)$(LOCAL_INCLUDE_DEST)

clean distclean:

.PHONY: install clean distclean