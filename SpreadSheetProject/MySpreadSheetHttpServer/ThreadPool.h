#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#ifndef __INCLUDE_CHRONO__
#define __INCLUDE_CHRONO__
#include <chrono>
#endif

#ifndef __INCLUDE_CONDITION_VARIABLE__
#define __INCLUDE_CONDITION_VARIABLE__
#include <condition_variable>
#endif

#ifndef __INCLUDE_CSTDIO__
#define __INCLUDE_CSTDIO__
#include <cstdio>
#endif

#ifndef __INCLUDE_FUNCTIONAL__
#define __INCLUDE_FUNCTIONAL__
#include <functional>
#endif

#ifndef __INCLUDE_FUTURE__
#define __INCLUDE_FUTURE__
#include <future>
#endif

#ifndef __INCLUDE_MUTEX__
#define __INCLUDE_MUTEX__
#include <mutex>
#endif

#ifndef __INCLUDE_QUEUE__
#define __INCLUDE_QUEUE__
#include <queue>
#endif

#ifndef __INCLUDE_THREAD__
#define __INCLUDE_THREAD__
#include <thread>
#endif

#ifndef __INCLUDE_VECTOR__
#define __INCLUDE_VECTOR__
#include <vector>
#endif

#ifndef __USING_STD__
#define __USING_STD__
using namespace std;
#endif

namespace ThreadPool {
	class ThreadPool {
	public:
		ThreadPool(size_t num_threads);
		~ThreadPool();

		template <class F, class... Args>
		future<typename result_of<F(Args...)>::type> EnqueueJob(F&& f, Args&&... args);

	private:
		size_t num_threads_;
		vector<thread> worker_threads_;
		queue<function<void()>> jobs_;
		condition_variable cv_job_q_;
		mutex m_job_q_;

		bool stop_all;

		void WorkerThread();
	};
}

#endif