.PHONY: bump-major bump-minor bump-patch version

VERSION_FILE := VERSION

# Read current version
CURRENT_VERSION := $(shell cat $(VERSION_FILE))
MAJOR := $(word 1, $(subst ., ,$(CURRENT_VERSION)))
MINOR := $(word 2, $(subst ., ,$(CURRENT_VERSION)))
PATCH := $(word 3, $(subst ., ,$(CURRENT_VERSION)))

version:
	@echo $(CURRENT_VERSION)

bump-patch:
	@NEW_PATCH=$$(($(PATCH) + 1)); \
	NEW_VERSION="$(MAJOR).$(MINOR).$$NEW_PATCH"; \
	printf '%s' "$$NEW_VERSION" > $(VERSION_FILE); \
	echo "Bumped version: $(CURRENT_VERSION) -> $$NEW_VERSION"

bump-minor:
	@NEW_MINOR=$$(($(MINOR) + 1)); \
	NEW_VERSION="$(MAJOR).$$NEW_MINOR.0"; \
	printf '%s' "$$NEW_VERSION" > $(VERSION_FILE); \
	echo "Bumped version: $(CURRENT_VERSION) -> $$NEW_VERSION"

bump-major:
	@NEW_MAJOR=$$(($(MAJOR) + 1)); \
	NEW_VERSION="$$NEW_MAJOR.0.0"; \
	printf '%s' "$$NEW_VERSION" > $(VERSION_FILE); \
	echo "Bumped version: $(CURRENT_VERSION) -> $$NEW_VERSION"
