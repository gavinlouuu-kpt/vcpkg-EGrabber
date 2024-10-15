/* Copyright Euresys 2021 */

#ifndef EURESYS_GENAPI_BUILDER_HEADER_FILE
#define EURESYS_GENAPI_BUILDER_HEADER_FILE

namespace EURESYS_NAMESPACE {

namespace Internal {

class AtQualifier {
    public:
        AtQualifier(bool strict = false)
        : strict(strict)
        {}
        std::string qualify(const std::string &command) const { return ((strict) ? "@!" : "@") + command; }
    private:
        const bool strict;
};

} // namespace Internal

namespace query {

class GenApiQueryBuilder {
    public:
        GenApiQueryBuilder(const Internal::AtQualifier &atq, const std::string &command)
        : command(atq.qualify(command))
        {}
        GenApiQueryBuilder(const Internal::AtQualifier &atq, const std::string &command, const std::string &arg)
        : command(atq.qualify(command) + " " + arg)
        {}
        GenApiQueryBuilder(const Internal::AtQualifier &atq, const std::string &command, const std::string &arg, const std::string &arg2)
        : command(atq.qualify(command) + " " + arg + " " + arg2)
        {}
        operator std::string() const { return command; }
        std::string glob(const std::string &glob) const { return command + " =? " + glob; }
        std::string regex(const std::string &re) const { return command + " =~ " + re; }
    private:
        const std::string command;
};

inline GenApiQueryBuilder attributes() {
    return GenApiQueryBuilder(Internal::AtQualifier(), "attributes");
}
inline GenApiQueryBuilder features(bool availOnly) {
    return GenApiQueryBuilder(Internal::AtQualifier(availOnly), "features");
}
inline GenApiQueryBuilder featuresOf(const std::string &category, bool availOnly) {
    return GenApiQueryBuilder(Internal::AtQualifier(availOnly), "features", category);
}
inline GenApiQueryBuilder categories(bool availOnly) {
    return GenApiQueryBuilder(Internal::AtQualifier(availOnly), "categories");
}
inline GenApiQueryBuilder categoriesOf(const std::string &category, bool availOnly) {
    return GenApiQueryBuilder(Internal::AtQualifier(availOnly), "categories", category);
}
inline GenApiQueryBuilder enumEntries(const std::string &feature, bool availOnly) {
    return GenApiQueryBuilder(Internal::AtQualifier(availOnly), "ee", feature);
}
inline GenApiQueryBuilder available(const std::string &feature) {
    return GenApiQueryBuilder(Internal::AtQualifier(), "available", feature);
}
inline GenApiQueryBuilder readable(const std::string &feature) {
    return GenApiQueryBuilder(Internal::AtQualifier(), "readable", feature);
}
inline GenApiQueryBuilder writeable(const std::string &feature) {
    return GenApiQueryBuilder(Internal::AtQualifier(), "writeable", feature);
}
inline GenApiQueryBuilder implemented(const std::string &feature) {
    return GenApiQueryBuilder(Internal::AtQualifier(), "implemented", feature);
}
inline GenApiQueryBuilder command(const std::string &feature) {
    return GenApiQueryBuilder(Internal::AtQualifier(), "command", feature);
}
inline GenApiQueryBuilder done(const std::string &feature) {
    return GenApiQueryBuilder(Internal::AtQualifier(), "done", feature);
}
inline GenApiQueryBuilder interfaces(const std::string &feature) {
    return GenApiQueryBuilder(Internal::AtQualifier(), "interfaces", feature);
}
inline GenApiQueryBuilder source(const std::string &feature) {
    return GenApiQueryBuilder(Internal::AtQualifier(), "source", feature);
}
inline GenApiQueryBuilder xml() {
    return GenApiQueryBuilder(Internal::AtQualifier(), "xml");
}
inline GenApiQueryBuilder info(const std::string &feature, const std::string &what) {
    return GenApiQueryBuilder(Internal::AtQualifier(), "info", feature, what);
}
inline GenApiQueryBuilder declared() {
    return GenApiQueryBuilder(Internal::AtQualifier(), "declared");
}

} // namespace query

namespace action {

class GenApiActionBuilder {
    public:
        GenApiActionBuilder(const Internal::AtQualifier &atq, const std::string &command)
        : command(atq.qualify(command))
        {}
        operator std::string() const { return command; }
    private:
        const std::string command;
};

inline GenApiActionBuilder declareInteger() {
    return GenApiActionBuilder(Internal::AtQualifier(), "declare(integer)");
}
inline GenApiActionBuilder declareFloat() {
    return GenApiActionBuilder(Internal::AtQualifier(), "declare(float)");
}
inline GenApiActionBuilder declareString() {
    return GenApiActionBuilder(Internal::AtQualifier(), "declare(string)");
}
inline GenApiActionBuilder undeclare() {
    return GenApiActionBuilder(Internal::AtQualifier(), "undeclare");
}

} // namespace action

#ifdef EURESYS_USE_NS_EURESYS_DEPRECATED_API
inline std::string Features(bool availableOnly) {
    return query::features(availableOnly);
}
inline std::string RegexFeatures(const std::string &re, bool availableOnly) {
    return query::features(availableOnly).regex(re);
}
inline std::string GlobFeatures(const std::string &glob, bool availableOnly) {
    return query::features(availableOnly).glob(glob);
}
inline std::string EnumEntries(const std::string &feature, bool availableOnly) {
    return query::enumEntries(feature, availableOnly);
}
inline std::string RegexEnumEntries(const std::string &feature, const std::string &re, bool availableOnly) {
    return query::enumEntries(feature, availableOnly).regex(re);
}
inline std::string GlobEnumEntries(const std::string &feature, const std::string &glob, bool availableOnly) {
    return query::enumEntries(feature, availableOnly).glob(glob);
}
#endif
} // namespace EURESYS_NAMESPACE
#endif
