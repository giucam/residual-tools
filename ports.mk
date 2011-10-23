# This file contains port specific Makefile rules. It is automatically
# included by the default (main) Makefile.
#
# $URL: https://residual.svn.sourceforge.net/svnroot/residual/residual/trunk/ports.mk $
# $Id: ports.mk 1635 2010-01-21 19:25:03Z aquadran $


#
# UNIX specific
#
install: all
	$(INSTALL) -d "$(DESTDIR)$(BINDIR)"
	$(INSTALL) -c -s -m 755 $(EXECUTABLES) "$(DESTDIR)$(BINDIR)/"
	#$(INSTALL) -d "$(DESTDIR)$(PREFIX)/share/doc/residual-tools/"
	#$(INSTALL) -c -m 644 $(DIST_FILES_DOCS) "$(DESTDIR)$(PREFIX)/share/doc/residual-tools/"

PATHS := $(addprefix $(DESTDIR)$(BINDIR)/, $(EXECUTABLES))
uninstall:
	rm -f $(PATHS)
	#rm -rf "$(DESTDIR)$(PREFIX)/share/doc/residual-tools/"


#
# ARM specific
#
ifdef USE_TREMOLO
DEFINES += -DUSE_TREMOR -DUSE_VORBIS -DUSE_TREMOLO
LIBS += -ltremolo
endif

