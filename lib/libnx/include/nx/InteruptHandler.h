#pragma once
#include <nx/IKernelCapabilityHandler.h>
#include <nx/InteruptEntry.h>

namespace nx
{
	class InteruptHandler :
		public IKernelCapabilityHandler
	{
	public:
		InteruptHandler();

		bool operator==(const InteruptHandler& other) const;
		bool operator!=(const InteruptHandler& other) const;
		void operator=(const InteruptHandler& other);

		// kernel capabilty list in/out
		void importKernelCapabilityList(const fnd::List<KernelCapability>& caps);
		void exportKernelCapabilityList(fnd::List<KernelCapability>& caps) const;
		void clear();
		bool isSet() const;

		// variables
		const fnd::List<uint16_t>& getInteruptList() const;
		void setInteruptList(const fnd::List<uint16_t>& interupts);

	private:
		const std::string kModuleName = "INTERUPT_HANDLER";

		bool mIsSet;
		fnd::List<uint16_t> mInterupts;

		void copyFrom(const InteruptHandler& other);
		bool isEqual(const InteruptHandler& other) const;
	};
}

