%define version 5.0
%define dwarf_ver 20060327

Summary: An API for Runtime Code Generation
License: Copyright 1996-2006 Barton P. Miller
Name: dyninst
Group: Development/Libraries
Prefix: %_usr
Provides: dyninst
Release: 1
Source: dyninst-%{version}.tar.gz
URL: http://www.dyninst.org
Version: %version
Packager: <bugs@dyninst.org>
Exclusiveos: linux

Source0: dyninst-5.0.tar.gz
Source1: libdwarf-%{dwarf_ver}.tar.gz

%description

Dyninst is an Application Program Interface (API) to permit the insertion of
code into a running program. The API also permits changing or removing
subroutine calls from the application program. Runtime code changes are
useful to support a variety of applications including debugging, performance
monitoring, and to support composing applications out of existing packages.
The goal of this API is to provide a machine independent interface to permit
the creation of tools and applications that use runtime code patching.

%prep

%define platform %{_arch}-unknown-linux2.4
%ifarch x86_64
	%define _lib lib64
%endif

%setup -q -a 1

%build

cd dwarf-%{dwarf_ver}/libdwarf; ./configure; make

cd ../../core

cat > make.config.local << RPMEOF
LIBDWARFDIR = %{_builddir}/%{buildsubdir}/dwarf-%{dwarf_ver}/libdwarf
LIBDWARF_INC = %{_builddir}/%{buildsubdir}/dwarf-%{dwarf_ver}/libdwarf
LIBDWARF_LIB = %{_builddir}/%{buildsubdir}/dwarf-%{dwarf_ver}/libdwarf
LIBELFDIR = %_libdir
TCLTK_DIR = %_usr
RPMEOF

make DyninstAPI PLATFORM=%platform NO_OPT_FLAG=1

%install

%__install -d %{_includedir}/dyninst
%__install -d %{_datadir}/dyninst/tests

cd %{platform}/bin
%__install dyner %{_bindir}
cd testprogs
%__install * %{_datadir}/dyninst/tests
cd ../../lib
%__install libdyninstAPI_RT.so.1 libdyninstAPI.so %{_libdir}
cd ../../core/dyninstAPI/h
%__install * %{_includedir}/dyninst
cd ../../common/h
%__install * %{_includedir}/dyninst

%clean

rm -rf $RPM_BUILD_ROOT

%files

%{_bindir}/dyner
%{_includedir}/dyninst
%{_libdir}/libdyninstAPI_RT.so.1
%{_libdir}/libdyninstAPI.so
%doc dyninstProgGuide.pdf dynerGuide.pdf

%package tests

Group: Development/Libraries
Summary: The test suite for DyninstAPI
Requires: dyninst = %version

%description tests

A set of test cases to verify that Dyninst has been installed correctly
(and for use in regression testing by the developers of the Dyninst
library).

%files tests

%{_datadir}/dyninst/tests
