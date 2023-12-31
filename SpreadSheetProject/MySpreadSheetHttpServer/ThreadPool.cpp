#ifndef __INCLUDE_THREADPOOL__
#define __INCLUDE_THREADPOOL__
#include "ThreadPool.h"
#endif

namespace Thread {
	ThreadPool::ThreadPool(size_t num_threads)
		: num_threads_(num_threads), stop_all(false)
	{
		worker_threads_.reserve(num_threads_);
		for (size_t i = 0; i < num_threads_; ++i) {
			worker_threads_.emplace_back([this]() {this->WorkerThread(); });
		}
	}
	ThreadPool::~ThreadPool() {
		stop_all = true;
		cv_job_q_.notify_all();

		for (auto& t : worker_threads_) {
			t.join();
		}
	}

	/*template <class F, class... Args>
	future<typename result_of<F(Args...)>::type> ThreadPool::EnqueueJob(F&& f, Args&&... args) {
		if (stop_all) {
			throw runtime_error("ThreadPool is all stopped");
		}

		using return_type = typename std::result_of<F(Args...)>::type;
		auto job = std::make_shared<std::packaged_task<return_type()>>(
			bind(forward<F>(f), forward<Args>(args)...));
		future<return_type> job_result_future = job->get_future();
		{
			lock_guard<mutex> lock(m_job_q_);
			jobs_.push([job]() { (*job)(); });
		}
		cv_job_q_.notify_one();

		return job_result_future;
	}*/

	void ThreadPool::WorkerThread() {
		while (true) {
			unique_lock<mutex> lock(m_job_q_);
			cv_job_q_.wait(lock, [this]() {return !this->jobs_.empty() || stop_all; });
			if (stop_all && this->jobs_.empty()) {
				return;
			}

			function<void()> job = move(jobs_.front());
			jobs_.pop();
			lock.unlock();

			job();
		}
	}
};