<?php
namespace App\Controller;

use App\Controller\AppController;

/**
 * SpecialDates Controller
 *
 * @property \App\Model\Table\SpecialDatesTable $SpecialDates
 *
 * @method \App\Model\Entity\SpecialDate[] paginate($object = null, array $settings = [])
 */
class SpecialDatesController extends AppController
{

    /**
     * Index method
     *
     * @return \Cake\Http\Response|void
     */
    public function index()
    {
        $this->paginate = [
            'contain' => ['Houses']
        ];
        $specialDates = $this->paginate($this->SpecialDates);

        $this->set(compact('specialDates'));
        $this->set('_serialize', ['specialDates']);

        $this->Auth->allow(['findSpecialDates', 'addSpecialDate', 'deleteSpecialDate']);

        
    }

    /**
     * View method
     *
     * @param string|null $id Special Date id.
     * @return \Cake\Http\Response|void
     * @throws \Cake\Datasource\Exception\RecordNotFoundException When record not found.
     */
    public function view($id = null)
    {
        $specialDate = $this->SpecialDates->get($id, [
            'contain' => ['Houses']
        ]);

        $this->set('specialDate', $specialDate);
        $this->set('_serialize', ['specialDate']);
    }

    /**
     * Add method
     *
     * @return \Cake\Http\Response|null Redirects on successful add, renders view otherwise.
     */
    public function add()
    {
        $specialDate = $this->SpecialDates->newEntity();
        if ($this->request->is('post')) {
            $specialDate = $this->SpecialDates->patchEntity($specialDate, $this->request->getData());
            if ($this->SpecialDates->save($specialDate)) {
                $this->Flash->success(__('The special date has been saved.'));

                return $this->redirect(['action' => 'index']);
            }
            $this->Flash->error(__('The special date could not be saved. Please, try again.'));
        }
        $houses = $this->SpecialDates->Houses->find('list', ['limit' => 200]);
        $this->set(compact('specialDate', 'houses'));
        $this->set('_serialize', ['specialDate']);
    }

    /**
     * Edit method
     *
     * @param string|null $id Special Date id.
     * @return \Cake\Http\Response|null Redirects on successful edit, renders view otherwise.
     * @throws \Cake\Network\Exception\NotFoundException When record not found.
     */
    public function edit($id = null)
    {
        $specialDate = $this->SpecialDates->get($id, [
            'contain' => []
        ]);
        if ($this->request->is(['patch', 'post', 'put'])) {
            $specialDate = $this->SpecialDates->patchEntity($specialDate, $this->request->getData());
            if ($this->SpecialDates->save($specialDate)) {
                $this->Flash->success(__('The special date has been saved.'));

                return $this->redirect(['action' => 'index']);
            }
            $this->Flash->error(__('The special date could not be saved. Please, try again.'));
        }
        $houses = $this->SpecialDates->Houses->find('list', ['limit' => 200]);
        $this->set(compact('specialDate', 'houses'));
        $this->set('_serialize', ['specialDate']);
    }

    /**
     * Delete method
     *
     * @param string|null $id Special Date id.
     * @return \Cake\Http\Response|null Redirects to index.
     * @throws \Cake\Datasource\Exception\RecordNotFoundException When record not found.
     */
    public function delete($id = null)
    {
        $this->request->allowMethod(['post', 'delete']);
        $specialDate = $this->SpecialDates->get($id);
        if ($this->SpecialDates->delete($specialDate)) {
            $this->Flash->success(__('The special date has been deleted.'));
        } else {
            $this->Flash->error(__('The special date could not be deleted. Please, try again.'));
        }

        return $this->redirect(['action' => 'index']);
    }



public function isAuthorized($user)
    {
            
            $action = $this->request->getParam('action');
            if (strcmp($user['type'],"Administrador")==0) {
                return true;
            }
            return parent::isAuthorized($user);
    }


    public function findSpecialDates()
    {
        $especialDates = $this->SpecialDates->find('all');

        $this->set(compact('especialDates'));
        $this->set('_serialize', ['especialDates']);
    }

    public function addSpecialDate()
    {
    
        if ($this->request->is('post')) {

            $data= $this->request->getData();

            $s_t=date_create($data["start"]);
            $e_t=date_create($data["end"]);
            date_time_set($e_t,23,59,59);
            $horarios=$data["horarios"];
            $houses=$data["houses"];
            //$this->set(compact('s_t'));
            //$this->set('_serialize', ['s_t']);
            //return;
            $i=0;
            while($s_t<$e_t)
            {
                for($i1=0;$i1<count($houses);$i1++)
                {
                    $house=$houses[$i1];
                    for($i2=0;$i2<count($horarios);$i2++)
                    {
                        $horario=$horarios[$i2];

                        switch ($horario["hora"]) {
                            case "10:30:00":
                                date_time_set($s_t,10,30);
                                break;
                            case "12:00:00":
                                date_time_set($s_t,12,00);
                                break;
                            case "16:00:00":
                                date_time_set($s_t,16,00);
                                break;
                        }     
                        $query = $this->SpecialDates->query();
                        $query->insert(['date_time' ,'house_id'])
                            ->values([
                                'date_time' => $s_t->format('Y-m-d H:i:s'),
                                'house_id' => $house["house"]
                            ])
                            ->execute();
                        //$data["$i . $i1 . $i2"]=$s_t->format('Y-m-d H:i:s')." ". $house["house"];
                    }
                    

                } 
               $s_t->modify('+1 day');  
               $i++;    
            }

            
        }
        $this->set(compact('data'));
        $this->set('_serialize', ['data']);
    }

    public function deleteSpecialDate()
    {

        if ($this->request->is('post')) {

            $data= $this->request->getData();

            $s_t=date_create($data["start"]);
            $e_t=date_create($data["end"]);
            date_time_set($e_t,23,59,59);
            $horarios=$data["horarios"];
            $houses=$data["houses"];
            //$this->set(compact('s_t'));
            //$this->set('_serialize', ['s_t']);
            //return;
            $i=0;
            while($s_t<$e_t)
            {
                for($i1=0;$i1<count($houses);$i1++)
                {
                    $house=$houses[$i1];
                    for($i2=0;$i2<count($horarios);$i2++)
                    {
                        $horario=$horarios[$i2];

                        switch ($horario["hora"]) {
                            case "10:30:00":
                                date_time_set($s_t,10,30);
                                break;
                            case "12:00:00":
                                date_time_set($s_t,12,00);
                                break;
                            case "16:00:00":
                                date_time_set($s_t,16,00);
                                break;
                        }     
                        $query = $this->SpecialDates->query();
                        $query->delete()
                            ->where(['date_time' => $s_t->format('Y-m-d H:i:s'), 'house_id'=>$house["house"]])
                            ->execute();
                        
                        //$data["$i . $i1 . $i2"]=$s_t->format('Y-m-d H:i:s')." ". $house["house"];
                    }
                    

                } 
               $s_t->modify('+1 day');  
               $i++;    
            }

            
        }
        $this->set(compact('data'));
        $this->set('_serialize', ['data']);
    }



}
