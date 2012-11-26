#include <string>
#include <vector>
using namespace std;
class Account { 
 public:
  Account(const string& name, unsigned int balance, double interest_rate);
  virtual ~Account(){};
  
  void Deposit(unsigned int amount);
  bool Withdraw(unsigned int amount);
        
  virtual unsigned int ComputeExpectedBalance(
      unsigned int n_years_later) const{
		  return (balance_ * n_years_later * interest_rate_) + balance_;
  };
      
  virtual const char* type() const { return "normal"; }
  const unsigned int& balance() const { return balance_; }
  const string& name() const { return name_; }
  const double& interest_rate() const { return interest_rate_; }
        
 protected:
  string name_;
  unsigned int balance_;
  double interest_rate_;  // �⺻ ���´� �ܸ��� ���.
};           
             
class SavingAccount : public Account {
 public:
	 SavingAccount(const string& name, int balance, double interest_rate): Account(name,balance,interest_rate){};
	 virtual ~SavingAccount(){};
      
  virtual const char* type() const { return "saving"; }
  // �� Ÿ���� ���´� ������ ���.
  virtual unsigned int ComputeExpectedBalance(
      unsigned int n_years_later) const{
		  double temp = balance_;
		  double temp2;
		  for(int i=0;i<n_years_later;i++){
			  temp2 = temp *interest_rate_;
			  temp +=temp2;
		  }
		  return temp;
  };
};    
      
inline Account* CreateAccount(const string& type,
    const string& name, unsigned int balance, double interest_rate){
	if(type == "normal"){
		Account *a = new Account(name,balance,interest_rate);
		return a;
	}
	else{
		SavingAccount *a = new SavingAccount(name,balance,interest_rate);
		return a;
	}
}