#include <atomic>

class GUIDGenerator {
public:
    GUIDGenerator( const GUIDGenerator& ) = delete;
    void operator=( const GUIDGenerator& ) = delete;

    static GUIDGenerator& getInstance() {
        static GUIDGenerator instance;  // Guaranteed to be destroyed and instantiated only once
        return instance;
    }

    // Other member functions and data members
    int GenerateNewGUID() {
        const int lNewGUID = mCurrentIndex;
        ++mCurrentIndex;
        return lNewGUID;
    }

private:
    static std::atomic_int mCurrentIndex;

    GUIDGenerator() {
        mCurrentIndex = 0;
    }

    ~GUIDGenerator() = default;
};