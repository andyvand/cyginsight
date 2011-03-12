%define version 7.0
%define dwarf_ver 20110113
%define xml2_ver 2.7.8

Summary: An API for Runtime Code Generation
License: Copyright 1996-2009 Barton P. Miller
Name: dyninst
Group: Development/Libraries
Provides: dyninst
Release: 1
URL: http://www.dyninst.org
Version: %version
Packager: <bugs@dyninst.org>
Exclusiveos: linux

Source0: dyninst-%{version}.tar.gz
Source1: libdwarf-%{dwarf_ver}.tar.gz
Source2: libxml2-%{xml2_ver}.tar.gz

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
%setup -q -T -D -a 2

%build

cd dwarf-%{dwarf_ver}/libdwarf; ./configure CFLAGS="-fPIC -g -O2"; make libdwarf.so
cd ../..
cd libxml2-%{xml2_ver}; ./configure
cd ..
cd dyninst

./configure --with-libdwarf-libdir=%{_builddir}/%{buildsubdir}/dwarf-%{dwarf_ver}/libdwarf --with-libdwarf-incdir=%{_builddir}/%{buildsubdir}/dwarf-%{dwarf_ver}/libdwarf --with-libxml2-incdir=%{_builddir}/%{buildsubdir}/libxml2-%{xml2_ver}/include
make PLATFORM=%platform DONT_BUILD_NEWTESTSUITE=1 all parseThat StackwalkerAPI

%install

%__install -d %{buildroot}/%{_bindir}
%__install %{platform}/bin/parseThat %{buildroot}/%{_bindir}

%__install -d %{buildroot}/%{_libdir}/dyninst
%__install %{platform}/lib/* %{buildroot}/%{_libdir}/dyninst
%__install dwarf-%{dwarf_ver}/libdwarf/libdwarf.so %{buildroot}/%{_libdir}/dyninst

%__install -d %{buildroot}/%{_includedir}/dyninst
cp -pr include/* %{buildroot}/%{_includedir}/dyninst

%clean

rm -rf $RPM_BUILD_ROOT

%files
%defattr(-,root,root,-)

%{_bindir}/parseThat
%{_libdir}/dyninst/
%{_includedir}/dyninst/

%doc dyninstProgGuide.pdf
%doc symtabProgGuide.pdf
%doc instructionProgGuide.pdf
%doc parseapi.pdf
%doc ProcControlAPI.pdf
%doc stackwalker.pdf
%doc dynC_API.pdf
